/**
 * @file simple_drive_timed.c
 *
 * This is meant to be a skeleton program for Robot Control projects. Change
 * this description and file name before modifying for your own purpose.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <rc/start_stop.h>
#include <rc/encoder_eqep.h>
#include <rc/adc.h>
#include <robotcontrol.h> // includes ALL Robot Control subsystems
#include <rc/motor.h>
#include <rc/time.h>

// function declarations
void go_straight(float duty);
void turn_left(float duty);
void turn_right(float duty);


/**
 * This template contains these critical components
 * - ensure no existing instances are running and make new PID file
 * - start the signal handler
 * - initialize subsystems you wish to use
 * - while loop that checks for EXITING condition
 * - cleanup subsystems at the end
 *
 * @return     0 during normal operation, -1 on error
 */


int main(){
        float duty = 0.25;
        
	rc_motor_init();

        for(int i = 0; i < 4; i++){
                go_straight(duty);
                turn_left(duty);
        }
        
        rc_motor_cleanup();
        
}



void turn_right(float duty){
        // Go straight for 1s and stop
        rc_motor_set(1, duty);
        rc_motor_set(2, (float) -0.91*duty);
        rc_nanosleep(69E7);
        rc_motor_set(1, 0.0);
        rc_motor_set(2, 0.0);
}

void go_straight(float duty){
        // Turn left for 0.5s and stop
        rc_motor_set(1, duty);
        rc_motor_set(2, (float) 0.91*duty);
        rc_nanosleep(4E9);
        rc_motor_set(1, 0.0);
        rc_motor_set(2, 0.0);
}

void turn_left(float duty){
        // Turn left for 0.5s and stop
        rc_motor_set(1, -duty);
        rc_motor_set(2, (float) 0.91*duty);
        rc_nanosleep(69E7);
        rc_motor_set(1, 0.0);
        rc_motor_set(2, 0.0);
}
