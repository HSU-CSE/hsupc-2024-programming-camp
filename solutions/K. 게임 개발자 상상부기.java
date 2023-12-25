import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
/*
 * 
 *
 */
public class Main {
    static class ManageRoom{
        List<Room>data;
        public ManageRoom(){
            data=new ArrayList<>();
        }
        public boolean enterRoom(String title,int id){
            //어느 유저가 어느 방으로 들어가는지
            boolean flag=false;
            for(int i=0;i<data.size();i++){
                if(data.get(i).title.equals(title)){//내가 들어갈 방과 이름이 같다면
                    flag= data.get(i).users.add(id);
                    break;
                }
            }
            return flag;
        }
        public int isAlreadyMake(String title){//이미 만들어진 적이 있는지 적발
            int index = -1;
            for(int i=0;i<data.size();i++){
                if(data.get(i).title.equals(title)){
                    index=i;
                    break;
                }
            }
            return index;
        }
        public int gameStart(String title,int id){//어떤 아이가 게임을 시작했는지 중요함
            int ret = 0;
            for(Room r:data){
                if(r.getTitle().equals(title)){
                    if(r.getAdminId()==id){
                        ret = r.getUsers().size();
                    }
                }
            }
            return ret;
        }
        public boolean makeRoom(String title,int id){
            int index = isAlreadyMake(title);//이미 만들어진 적이 있는지 확인
            if(index!=-1){//이미 만들어진 적이 있으면 방장만 바꾸자.
                this.data.get(index).setAdminId(id);
                this.data.get(index).users.add(id);
                return false;
            }
            Room newRoom = new Room(title,id);
            newRoom.users.add(id);
            return data.add(newRoom);
        }
        public boolean gameEnd(String title, int id) {
            boolean ret = false;
            for(int i=0;i<data.size();i++){//10000
                Room r = data.get(i);
                if(r.getTitle().equals(title)){
                    if(r.getAdminId() == id){
                        ret = true;
                    }
                    data.remove(i);//10000번
                    break;
                }
            }
            return ret;
        }
    }
    static class Room{
        private String title;
        private List<Integer>users;
        private int adminId;
        public Room(String title,int id){
            this.users = new ArrayList<>();
            this.title =title;
            this.adminId =id;
        }
        public int getAdminId() {
            return adminId;
        }
        public void setAdminId(int adminId) {
            this.adminId = adminId;
        }
        public String getTitle() {
            return title;
        }
        public List<Integer> getUsers() {
            return users;
        }
        public void setTitle(String title) {
            this.title = title;
        }
        public void setUsers(List<Integer> users) {
            this.users = users;
        }
    }
    static class Error{
        private String time;
        private int id;
        public Error(String time,int id){
            this.time = time;
            this.id = id;
        }
        public int getId() {
            return id;
        }
        public String getTime() {
            return time;
        }
        public void setId(int id) {
            this.id = id;
        }
        public void setTime(String time) {
            this.time = time;
        }
    }
    public static void errorAdd(List<Error>errors,Error newError,boolean[] Already){
        int id = newError.getId();
        if(Already[id])return;
        errors.add(newError);
        Already[id]=true;
    }
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();//결과
        StringTokenizer log;
        List<Error>errors = new ArrayList<>();
        boolean[] Numbering = new boolean[10002];

        ManageRoom mr = new ManageRoom();

        int n = Integer.parseInt(br.readLine());
        int continueCnt = 0;
        for(int i=0;i<n;i++){//n번
            log = new StringTokenizer(br.readLine());
            String time = log.nextToken();
            int id = Integer.parseInt(log.nextToken());
            String mode = log.nextToken();
            if(continueCnt!=0){//게임 시작하면 게임중이라는 키워드가 연달아서 나오기에
                continueCnt--;continue;
            }
            switch (mode) {
                case "make"->{
                    String title = log.nextToken();
                    boolean flag = mr.makeRoom(title, id);
                    if(!flag){//만들기 실패
                        errorAdd(errors, new Error(time,id), Numbering);
                    }
                }   
                case "into"->{
                    String title = log.nextToken();
                    mr.enterRoom(title, id);
                }   
                case "start"->{
                    String title = log.nextToken();
                    continueCnt =mr.gameStart(title, id);
                    if(continueCnt==0){//id 안 맞는 아이가 시작함.
                        errorAdd(errors, new Error(time,id), Numbering);
                    }
                }  
                case "end"->{
                    String title = log.nextToken();
                    boolean flag =mr.gameEnd(title, id);
                    if(!flag)errorAdd(errors, new Error(time, id), Numbering);
                }
            }
        }
        for(Error output:errors){
            System.out.println(output.getTime() + " " +output.getId());
        }
    }
}