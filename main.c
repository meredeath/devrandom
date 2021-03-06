#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){

  //opening the file of rng
  printf("results of first array\n");
  int f = open("/dev/random",O_RDONLY);

  //error handling
  if(f == -1){
    printf("read did not work");
  }

  //okay so assuming your reading did work:
  
  else{
    //creates initial array to populate
    unsigned int rands[10];
    read(f, rands, sizeof(int)*10); //reading
    
    //printing the ints that were read
    for(int i=0; i<10; i++){
      printf("number %d of array: %u\n", i, rands[i]);
    }

    printf("writing: \n");
    int written = open("stuff", O_WRONLY | O_CREAT, 0744);
    write(written, rands, sizeof(int)*10);
    
    printf("printing results of second array (what we wrote)\n");
    int check = open("stuff", O_RDONLY);

    //creating second array of unsigned ints to read into from written file
    unsigned int second[10];

    read(check, second, sizeof(int)*10); //reading

    //printing second array to see if it's the same
    for(int i=0; i<10; i++){
      printf("random number %d in second array: %u\n",i,second[i]);
    }

    //closing files that need closing
    close(f);
    close(written);
  }
  return 0;
}
