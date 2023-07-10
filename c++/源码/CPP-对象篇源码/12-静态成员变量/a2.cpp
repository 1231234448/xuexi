class T{
public:
    static T* get_instance(){
        if(pObj==NULL) pObj = new T();
        return pObj;
    }
    static void free(){
        if(pObj){
            delete pObj;
            pObj = NULL;
        }
    }
private:
    T(){}
    ~T(){}
    static T* pObj;
};

T* T::pObj = NULL; // 不要忘记真正创建变量

int main()
{
    T* p1 = T::get_instance();
    T* p2 = T::get_instance();
    cout << (p1 == p2) << endl;
    return 0;
}