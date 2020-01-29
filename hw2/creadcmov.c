//more efficent function
long cread_alt(long *xp)
{
    //doing it with just addresses, still uses jump statement without static
    static long prev_value  = -1;//could be garbage but doesnt matter rn
    long* default_address = &prev_value;
    long* prev_address = xp-1;
    long test = !xp;
    if(test) prev_address = default_address;
    return *prev_address;
}
