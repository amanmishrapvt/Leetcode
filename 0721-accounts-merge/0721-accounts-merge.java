class Solution {
    int[] parent;
    int[] rank;
    public int find(int i){
        if(parent[i]!=i){
            parent[i]=find(parent[i]);
        }
        return parent[i];
    }
    public void union(int a,int b){
        int roota=find(a), rootb=find(b);
        if(roota==rootb) return;
        int ranka=rank[roota], rankb=rank[rootb];
        if(rankb>ranka){
            parent[roota]=rootb;
            rank[rootb]++;
        }
        else{
            parent[rootb]=roota;
            rank[roota]++;
        }
    }
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        Map<String,Integer> emailToId=new HashMap<>();
        Map<String,String> emailToName=new HashMap<>();

        int id=0;
        for(List<String> acc: accounts){
            String name=acc.get(0);
            for(int i=1;i<acc.size();i++){
                String email=acc.get(i);
                if(emailToId.containsKey(email)) continue;
                emailToId.put(email, id++);
                emailToName.put(email, name);
            }
        }

        parent=new int[id];
        rank=new int[id];
        for(int i=0;i<id;i++) parent[i]=i;

        for(List<String> acc: accounts){
            int firstmail=emailToId.get(acc.get(1));
            for(int i=2;i<acc.size();i++){
                union(firstmail,emailToId.get(acc.get(i)));
            }
        }

        Map<Integer,List<String>> groups=new HashMap<>();
        for(String email: emailToId.keySet()){
            int root=find(emailToId.get(email));
            groups.putIfAbsent(root,new ArrayList<>());
            groups.get(root).add(email);
        }

        List<List<String>> result=new ArrayList<>();
        for(List<String> emails: groups.values()){
            Collections.sort(emails);
            List<String> merged=new ArrayList<>();
            merged.add(emailToName.get(emails.get(0)));
            merged.addAll(emails);
            result.add(merged);
        }

        return result;
    }
}