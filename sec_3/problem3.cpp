void convertSeconds(int sec)
{
    int hours = sec / 3600;
    
    int rem = sec % 3600; // how may seconds are left
    
    int min = rem / 60;
    
    int sec = rem % 60;
    
    
    cout << "hours: " << hours << "minutes: " << min << ", seconds: " << sec << endl;
    
}

int main()
{
    convertSeconds(86400);
    return 0;
}