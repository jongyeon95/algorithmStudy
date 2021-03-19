import java.util.*;
class Solution {
    public static int index = 0;
    public static List<Node> list = new ArrayList<Node>();
    public int[][] solution(int[][] nodeinfo) {
        int[][] answer=new int[2][nodeinfo.length];
        
        for(int i=0; i<nodeinfo.length;i++){
            list.add(new Node(nodeinfo[i][1],nodeinfo[i][0],i+1));
        }
        
        Collections.sort(list);
        Node root=list.get(0);
        for(int i=1; i<list.size(); i++){
            addNode(root,list.get(i));
        }
        preorder(answer, root);
        index = 0;
        postorder(answer, root);
        
        return answer;
    }
    
   public static void preorder(int[][] arr, Node root) { 

        if (root != null) {
            arr[0][index++] = root.num;
            preorder(arr, root.left);
            preorder(arr, root.right);
        }
    }

     public static void postorder(int[][] arr, Node root) { 
        if (root != null) {
            postorder(arr, root.left);
            postorder(arr, root.right);
            arr[1][index++] = root.num;
        }
    }
    
    
    public static void addNode(Node parent, Node child) {
        if (parent.x > child.x) {
            if (parent.left == null) {
                parent.left = child;
            } else {
                addNode(parent.left, child);
            }
        } else {
            if (parent.right == null) {
                parent.right = child;
            } else {
                addNode(parent.right, child);
            }
        }
    }
}

class Node implements Comparable<Node>{
    int y;
    int x;
    int num;
    Node left;
    Node right;
    
    public Node(int y, int x, int num){
        this.y=y;
        this.x=x;
        this.num=num;   
    }
    
    @Override
    public int compareTo(Node o){
        if(this.y==o.y)
            return this.x-o.x;
        return o.y-this.y;
    }
    
}