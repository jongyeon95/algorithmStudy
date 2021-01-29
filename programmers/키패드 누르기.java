class Solution {
    public String solution(int[] numbers, String hand) {
        StringBuilder str=new StringBuilder();
        int numberLocate[][]={{3,1},{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2},{3,0},{3,2}};
        int left=10;
        int right=11;
        for(int i=0; i<numbers.length; i++){
            int number= numbers[i];
            if(number==1||number==4||number==7){
                left=number;
                str.append("L");
            }
            else if(number==3||number==6||number==9){
                right=number;
                str.append("R");
            }
            else{
                int leftDist=Math.abs(numberLocate[number][0]-numberLocate[left][0])
                                      +Math.abs(numberLocate[number][1]-numberLocate[left][1]);
                int rightDist=Math.abs(numberLocate[number][0]-numberLocate[right][0])
                                      +Math.abs(numberLocate[number][1]-numberLocate[right][1]);
                if(leftDist<rightDist){
                    left=number;
                    str.append("L");
                }
                else if(leftDist>rightDist){
                    right=number;
                    str.append("R");
                }
                else{
                    if(hand.equals("right")){
                        right=number;
                        str.append("R");
                    }
                    else{
                        left=number;
                        str.append("L");
                    }            
                }
            }
        }
        String answer = str.toString();
        return answer;
    }
}