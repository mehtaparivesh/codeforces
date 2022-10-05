class LUPrefix {
public:
    set<int>sss;
    int size1;
    LUPrefix(int n) {
        size1=n;
        for(int i=1;i<=n;i++){
            sss.insert(i);
        }
    }
    
    void upload(int video) {
        if(sss.find(video)!=sss.end())sss.erase(sss.find(video));
        
    }
    
    int longest() {
        if(sss.size()==0)return size1;
        else return *sss.begin()-1;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */