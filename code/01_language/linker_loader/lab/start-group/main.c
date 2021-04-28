#include "a.h"
#include "b.h"

int main()
{
    a_f1();
}
/** gcc main.c 
 * -L /home/wsl/user/code/MyCode/code/01_language/linker_loader/lab/start-group 
 * -Xlinker --start-group 
 * -lb -la 
 * -Xlinker --end-group
 **/