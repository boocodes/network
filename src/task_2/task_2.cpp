#include "task_2.hpp"


void char_arr_pusher(char* target_arr, int target_arr_size, char* data)
{
    
    int last_char_pos = 0;
    for(size_t i = 0; ; i++)
    {
        if (!target_arr[i] == '\0')
        {
            last_char_pos++;
        }
        else{
            break;
        }
    }
    for(size_t i = 0; ; i++)
    {
        if(data[i] == '\0' || last_char_pos >= target_arr_size)
        {
            break;
        }
        else
        {
            target_arr[last_char_pos] = data[i];
            last_char_pos++;    
        }
        
    }
    
}

void convert_hex_to_bin(const char* hex_msg, char* new_bin_msg)
{
    int hex_msg_size = 0;
    for(size_t i = 0; ; i++)
    {
        if(hex_msg[i] == '\0') break;
        else
        {
            if(hex_msg[i] == ' ') hex_msg_size++; 
        }
    }
    char *new_bin_msg{ new char[hex_msg_size * 4] };
    for(size_t i = 0; ; i++)
    {
        if(hex_msg[i] == '\0') break;
        else
        {
            // switch (hex_msg[i])
            // {
            // case '0':
            //     new_bin_msg[i] = ""
            //     break;
            
            // default:
            //     break;
            // }
        }
    }
}

bool task_2()
{
    const char *FIO = "D4 E5 EB FC EA E5 F0 20 CD E8 EA E8 F2 E0 20 C2 E8 F2 E0 EB FC E5 E2 E8 F7 20 31 30 2E 30 36 2E 32 30 30 33";

}