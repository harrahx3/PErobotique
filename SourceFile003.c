#pragma config(Sensor, S1,     eyes,           sensorEV3_Ultrasonic)
#pragma config(Sensor, S2,     redButton,      sensorNone)
#pragma config(Motor,  motorA,          motorEyes,     tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          motorRight,    tmotorEV3_Large, PIDControl, reversed, encoder)
#pragma config(Motor,  motorC,          motorLeft,     tmotorEV3_Large, PIDControl, reversed, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "config.c"
#include "position.c"
#include "movement.c"
#include "sonar.c"

task displayPos() {
	struct PosData pos;
	while (true) {
		getPosition(&pos);
		displayBigTextLine(1, "S : %6.2f", SensorValue[eyes]);

		wait1Msec(50);
	}
}


task main()
{

	startTask(displayPos);
	int i = 1;
	float target = -45;
	int robotSpeed = 40;
	int eyesSpeed = 100;


	while(true){
		setMotorSpeed(motorLeft, robotSpeed);
		setMotorSpeed(motorRight, -robotSpeed);

		while(getUSDistance(eyes) > 35) {

			setMotorTarget(motorEyes, target, eyesSpeed);

			//Holds program flow until the motor on port A comes to a complete stop.
			waitUntilMotorStop(motorEyes);

			target += 10*i;
			if (abs(target) >= 45)
				i *= -1;

		}

		setMotorSpeed(motorRight, 0);
		setMotorSpeed(motorLeft, 0);


		while (getUSDistance(eyes)<40) {

		}

	}

}