import java.util.*;
class Song implements Comparable<Song>{
    int index;
    int play;

    public Song(int index, int play){
        this.index=index;
        this.play=play;
    }

    @Override
    public int compareTo(Song o){
        if(o.play==this.play){
            return this.index-o.index;
        }
        return o.play-this.play;
    }
}

class SongInfo implements Comparable<SongInfo> {
    PriorityQueue<Song> pq;
    int total;

    public SongInfo(){
        this.total=0;
        this.pq=new PriorityQueue<Song>();
    }

    @Override
    public int compareTo(SongInfo o){
        return o.total-this.total;
    }

}


class Solution {
    public int[] solution(String[] genres, int[] plays) {
        int[] answer = {};
        HashMap<String,SongInfo> hm=new HashMap<>();
        for(int i=0; i<genres.length; i++){
            if(hm.get(genres[i])==null){
                hm.put(genres[i],new SongInfo());
                hm.get(genres[i]).pq.offer(new Song(i,plays[i]));
                hm.get(genres[i]).total+=plays[i];
            }
            else{
                hm.get(genres[i]).pq.offer(new Song(i,plays[i]));
                hm.get(genres[i]).total+=plays[i];
            }
        }
        ArrayList<Integer> result=new ArrayList<>();
        PriorityQueue<SongInfo> pq=new PriorityQueue<SongInfo>();
        for(SongInfo temp : hm.values()){
            pq.offer(temp);
        }
        while(!pq.isEmpty()){
            SongInfo temp=pq.poll();
            int cnt=2;
            while(cnt>0&&!temp.pq.isEmpty()){
                result.add(temp.pq.poll().index);
                cnt--;
            }
        }

        return result.stream().mapToInt(i->i).toArray();
    }
}