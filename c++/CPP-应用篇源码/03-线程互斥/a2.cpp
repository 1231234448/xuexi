timed_mutex g1;

void f()
{
    this_thread::sleep_for(chrono::seconds(1));
    if(!g1.try_lock_for(chrono::seconds(3)))
        cout << "fail .. " << endl;
    else{
        cout << "ok.." << endl;
        g1.unlock();
    }
}
int main()
{
    thread th(f);
    g1.lock();
    cin.ignore();
    g1.unlock();

    th.join();

    return 0;
}