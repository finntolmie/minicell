#include <ctype.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_cell {
  uint32_t row;
  uint32_t col;
  char *literal;
  uint32_t len;
} cell;

int is_expr_cell(cell *cl) { return cl->len > 0 && cl->literal[0] == '='; }

int is_number_cell(cell *cl) {
  for (uint32_t i = 0; i < cl->len; i++) {
    if (!isdigit(cl->literal[i]))
      return 0;
  }
  return 1;
}

int is_str_cell(cell *cl) { return !is_number_cell(cl); }

// assumes that the pointer has advanced past the '='
int col_alpha_to_num(char *s) {
  if (s == NULL || s[0] == '\0') {
    return -1;
  }
  int res = 0;
  for (; *s != '\0'; s++) {
    if (!isalpha(*s)) {
      return res - 1;
    }
    char c = toupper(*s);
    res = res * 26 + (c - 'A' + 1);
    if (res < 0) {
      return -1;
    }
  }
  return res - 1;
}

int main() {
  char *test = "ZZZZ";
  printf("%d\n", col_alpha_to_num(test));
}