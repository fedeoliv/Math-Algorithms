#include <stdio.h>
#include <stdlib.h>

/*  Find angle between hands of an analog clock.
    The idea is to take 12:00 (h = 12, m = 0) as a reference. Following are detailed steps.

    1) Calculate the angle made by hour hand with respect to 12:00 in h hours and m minutes.
    2) Calculate the angle made by minute hand with respect to 12:00 in h hours and m minutes.
    3) The difference between two angles is the angle between two hands.

    How to calculate the two angles with respect to 12:00?
    The minute hand moves 360 degree in 60 minute(or 6 degree in one minute) and hour hand moves 360 degree
    in 12 hours(or 0.5 degree in 1 minute). In h hours and m minutes, the minute hand would move (h*60 + m)*6
    and hour hand would move (h*60 + m)*0.5.

    Input:  h = 12:00, m = 30.00
    Output: 165 degree */

int min(int x, int y) { return (x < y)? x: y; }

int calcAngle(double h, double m) {
    /*  Validate the input */
    if(h <0 || m < 0 || h >12 || m > 60) printf("Wrong input");

    if (h == 12) h = 0;
    if (m == 60) m = 0;

    /*  Calculate the angles moved by hour and minute hands with reference to 12:00 */
    int hour_angle = 0.5 * (h*60 + m);
    int minute_angle = 6*m;
    int angle = abs(hour_angle - minute_angle); /*Difference between two angles */

    /*  Return the smaller angle of two possible angles */
    angle = min(360-angle, angle);

    return angle;
}

int main() {
    double h, m;
    scanf("%lf %lf", &h, &m);
    printf("%d \n", calcAngle(h, m));
    return 0;
}
