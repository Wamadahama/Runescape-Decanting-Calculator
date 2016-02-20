#ifndef DECANTER_H
#define DECANTER_H

typedef struct {
  int one_count;
  int two_count;
  int three_count;
  int four_count;
  int total;
} potion_data;

potion_data* get_potion_data();
potion_data* decant_potion(potion_data* data);
void print_potion_data(potion_data* data);

#endif
