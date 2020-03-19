// Midterm exam – The C Programming Language, Spring 2020
// (Coding section – 52 points)
// POST ALL of this CODE to your ______.github.io portfolio.
// (8 pts) (1) Find any and all mistakes in the following code, and correct them.
#include <stdio.h>
#include <stdlib.h>

void count() {
 printf("Enter lines of text here: .../n");
 int c, nc = 0, nt = 0, nbackslash = 0;
 while ((c = fgetc(stderr)) != EOF) {
 if (c == '\n') { ++nl;
 } else if (c == '\t') { ++nt;
 } else if (c == '\\') { nbackslash += 1;
 } else if (isalnum(c)) { ++nc; }
 printf("lines: %s\n", nl);
 printf("tabs: %s\n", nt);
 printf("backslashes: %d\n", nbackslash);
 printf("alphanumeric: %d\n", nc);
}

int main(int argc, const char* argv[]) {
 count();
 return 0;
}


// The C Standard Library: Identify the standard library functions that do the following…
// (3 pts) (2) Find the first character c in a const char* s: _strchr()_________________________
// (3 pts) (3) Find the length of the prefix of const char* s that has characters in const char* t: __strspn() __________________
// (3 pts) (4) Terminate a program immediately ___exit()______________________________
// (3 pts) (5) Open the file “midterm.txt” in read mode ____fopen()_______________________


char* strcpy(char* s, const char* t){

  char* p = s;
  while ((*s++ = *t++) != '\0') { }

  return p;
}

char* strncat(char* s, const char* t, size_t n){
  char* p = s;

  while (*s != '\0') { ++s; }
  while (n-- > 0 && *t != '\0') {
    *s++ = *t++;
  }

  *s = '\0';
  return p;
}


int strcmp(const char* s, const char* t){

  while (*s != '\0' && *t != '\0' && *s == *t) {
      ++s;
      ++t;
    }
  return *s - *t;
}



// PART III: SHORT PROGRAM
//(20 pts) (9) Fill in the program code below for the square ADT (abstract data type)
//------ POINT ----------------------------------------------------------------
typedef struct point point;
struct point { double x, y; };
//------ SQUARE -----------------------------------------------------------------
typedef struct square square;
struct square { point ul; size_t side; };

square* square_init(double ulx, double uly, double side){


	point* pt  = (point*)malloc(sizeof(point));
	pt->ulx = ulx;
	pt->uly = uly;

  return pt;


}       //TODO
void square_delete(square* sq) {free(sq);} // TODO

void square_move(square* sq, double x, double y){

  sq->ul = x;
	sq->ul = y;


} // TODO
void square_expandby(square* sq, double expandby); // TODO
double square_area(square* sq); // TODO

double square_perimeter(square* r){
  double per = r->side;
  return 4 * per;

} // TODO
// print location, side, area and perimeter
void square_print(const char* msg, square* sq){

  char buf[BUFSIZE];
	memset(buf, 0, sizeof(buf))
	printf("%s%s\n", msg, sq);

} // TODO
void test_square(double ulx, double uly, double side) {
square* sq = square_init(ulx, uly, side);
square_print(“sq is: “, sq);
square_move(2, 2);
square_print(“sq is now: “, sq);
square_expandby(sq, 10);
square_print(“sq has expanded to: “, sq);
square_delete(sq);
printf(“\n\n”);
}
void tests_square() {
test_square(0, 0, 10);
test_square(1, 1, 5);
// add other tests if you wish // TODO (optional)
}
int main(int argc, const char* argv[]) {
tests_square();
return 0;
}
