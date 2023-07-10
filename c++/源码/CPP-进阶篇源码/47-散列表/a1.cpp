typedef unordered_map<string, int> my_map;
int main()
{
    my_map a = {{"us",10},{"uk",20},{"fr",30},{"de",40}};
    for(int i=0; i<a.bucket_count(); ++i){
        cout << "bucket " << i << ": " << "has ";
        cout << a.bucket_size(i) << endl;
    }

    cout << a["de"] << endl;
    cout << a.at("cc") << endl;
    return 0;
}