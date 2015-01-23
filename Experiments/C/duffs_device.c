/* An implementation of the famous duff's device compiler trick.
 */

#include <stdio.h>
#include <stdlib.h>

int duffs_device (char *from, char *to, int count);

int 
main (void)
{
	int   bytes_read;
    int   bytes_copied;
    int   buff_siz = 20;
    char *my_name;
    char *name_cp;	// To be used to copy the name from my_name using duff's device
	
    puts ("Please enter your name.");

    my_name = malloc (buff_siz + 1);
    bytes_read = getline (&my_name, &buff_siz, stdin);

    if (bytes_read == -1)
      {
        perror ("Insufficient input.");
        return -1;
      }

    name_cp = malloc (buff_siz + 1);
    bytes_copied = duffs_device (my_name, name_cp, bytes_read);
    
    if (bytes_read == bytes_copied)
      {
        puts ("Success. Your name in the second buffer is:");
        puts (name_cp);
      }
    else
      {
        perror ("Failed to copy as many bytes as there were read.");
        return -1;
      }

    return 0;
}


int
duffs_device (char *from, char *to, int count)
{
    {
        int n = (count + 7) / 8;

        switch (count % 8) {
            case 0: do {
                *to++ = *from++;
                case 7: *to++ = *from++;
                case 6: *to++ = *from++;
                case 5: *to++ = *from++;
                case 4: *to++ = *from++;
                case 3: *to++ = *from++;
                case 2: *to++ = *from++;
                case 1: *to++ = *from++;
            } while (--n > 0);
        }
    }

    return count;
}
