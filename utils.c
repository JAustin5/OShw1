// -----------------------------------
// CSCI 340 - Operating Systems I 
// Spring 2023 (Anthony Leclerc)
// utils.c implementation file
// Homework Assignment 1
//
// -----------------------------------

// these are the ONLY library header files that can be used. Under no
// circumstances can additional library header files be included.  In
// particular, this restriction means you CANNOT USE any function
// declared in <string.h>, which includes functions such as: strtok(),
// strchr(), strstr(), strlen(), index(), and others.

// NOTE: when you compile, DO NOT IGNORE WARNINGS!  These warnings are
// likely indicating you are doing something wrong, such as using a
// library function that you are not allowed to use or passing the
// wrong type of argument into a function.

#include <stdio.h>	// standard I/O functions
#include <stdlib.h> 	// atof()
#include <math.h>	// math functions

#include "utils.h"	// user defined functions

// see utils.h for the required function prototypes and specifications

// NOTE: you may add any "helper" functions you need to get the job done.
//       for example, if you need to determine the length of a string.

// put your IMPLEMENTATION of the function prototypes below:


int read_lines(char* filename, line_t* line_arr, int n) {
    
    FILE *fp;
    fp = fopen(filename, "r");
    char arrC[100];
    double fx = 0;
    double fx2 = 0;
    
    int lineCounter = 0;
    int i;
    
    point_t point0 = line_arr -> p0;
    point_t point1 = line_arr -> p1;
    
    line_t holder;
	
    double x0 = 0;
    double x1 = 0;
    double y0 = 0;
    double y1 = 0;
    
	
	while (fgets(arrC, 100, fp) != NULL) {
		int j = 0;
		for(i = 0; arrC[i] != '\n'; i++) {
			if(arrC[i] == ',') {
                fx = atof(arrC + j);
                j = i + 1;
                if(x1 == 0.0) {
                    x0 = fx;
                }
                else if (y0 == 0) {
                    y0 = fx;
                }
                else if (x1 == 0) {
                    x1 = fx;
                }
                else {
                    break;
                    
            }
        }
    }
        lineCounter++;
        fx2 = atof(arrC+j);
        y1 = fx2;
        
        point0.x = x0;
        point0.y = y0;
        point1.x = x1;
        point1.y = y1;
        
        
        holder.p0 = point0;
        holder.p1 = point1;

        
        line_arr[lineCounter] = holder;
        x0 = 0;
        x1 = 0;
        y0 = 0;
        y1 = 0;
    }
    fclose(fp);
    return lineCounter;
}


double calc_direction(line_t* line_ptr) {
	point_t point1 = line_ptr -> p0; 
	point_t point2 = line_ptr -> p1;  
	
	double x0 = point1.x;
	double y0 = point1.y;
	double x1 = point2.x;
	double y1 = point2.y;
	
    double dir = atan2(y1 - y0, x1 - x0);
	return dir;
}

double calc_magnitude(line_t* line_ptr) {
	point_t point1 = line_ptr -> p0;
	point_t point2 = line_ptr -> p1;
	
	double x0 = point1.x;
	double y0 = point1.y;
	double x1 = point2.x;
	double y1 = point2.y;
	
	double mag = sqrt(pow((x1 - x0), 2) + pow((y1 - y0), 2));
	return mag;
}