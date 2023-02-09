/* implementation set_bit */
int set_bit(int x, int y)
    {
        int result=x|(1<<y);
        return result;
    }
/* implementation clear_bit */
int clear_bit(int x, int y)
    {
        int result=x&(~(1<<y));
        return result;
    }
/* implementation toggle_bit */
int toggle_bit(int x, int y)
    {
        int result=(x^(1<<y));
        return result;
    }
/* implementation get_bit */
int get_bit(int x, int y)
    {
        int desired_bit=1;
        int test=set_bit(x,y);
        if (test==x)
    {
            return desired_bit;

    }
        else
        {
            return 0;
        }
    }



