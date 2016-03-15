#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Decanter.h"

/* Used to get the user input */
static char buffer[2048];
char* readline(char* prompt){
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char* cpy = malloc(strlen(buffer) + 1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy)-1] = '\0';
  return cpy;
}

/* Fills a potion_data struct based on user input */
potion_data* get_potion_data(){

    potion_data* user_input = malloc(sizeof(potion_data));

    char* input;
    int total = 0;

    puts("1/4th Potion Count");
    input = readline(":");
    user_input->one_count = atoi(input);
    total += user_input->one_count;

    puts("2/4th Potion Count");
    input = readline(":");
    user_input->two_count = atoi(input);
    total += user_input->two_count;

    puts("3/4th Potion Count");
    input = readline(":");
    user_input->three_count = atoi(input);
    total += user_input->three_count;

    puts("4/4th Potion Count");
    input = readline(":");
    user_input->four_count = atoi(input);
    total += user_input->four_count;

    user_input->total = total;
    return user_input;
}

potion_data* decant_potion(potion_data* data) {
  
  potion_data* return_data = malloc(sizeof(potion_data));
  
  /* Get the total ammount of doses */
  int dose_count = 0;
  
  dose_count += (data->four_count * 4);
  dose_count += (data->three_count * 3);
  dose_count += (data->two_count * 2);
  dose_count += (data->one_count);

  /*
   Get the total ammount of full potions and then fill in what remains
  */
  int full_potion_count = (dose_count / 4);

  return_data->four_count = full_potion_count;

  int remaining;
  remaining = dose_count % 4;

  /*
    There is only ever going to be one potion that isn't full after a decanting, for example
    903 (3) Potions are always going to be 675 (4) and 1 (3). But there is never a case where there will be something like:
    
   (4) : 25
   (3) : 0
   (2) : 1
   (1) : 1
   
   Because the (2) and the (1) would combine to make a (3), with this we can observe that every combination will have n 
   amount of potions(4) and one potion that is either (1), (2), or (3)
  */
  
  if (remaining == 1) {
    return_data->one_count = 1;
  } else {
    return_data->one_count = 0;
  }

  if (remaining == 2){
    return_data->two_count = 1;
  } else {
    return_data->two_count = 0;
  }

  if (remaining == 3) {
    return_data->three_count = 1;
  }
  else{
    return_data->three_count = 0;
  }
  
  /* Print exit information*/
  printf("Full potion count %i\n", full_potion_count );
  printf("Total number of doses: %i\n", dose_count);

  return return_data;
}

/* Print out the potion_data structure  */
void print_potion_data(potion_data* data){
  printf("1/4 potions: %i\n", data->one_count);
  printf("2/4 potions: %i\n", data->two_count);
  printf("3/4 potions: %i\n", data->three_count);
  printf("4/4 potions: %i\n", data->four_count);
}


int main(int argc, char const *argv[]) {
  potion_data* user_input = get_potion_data();
  potion_data* decanted_potion = decant_potion(user_input);
  print_potion_data(decanted_potion);
  return 0;
}
