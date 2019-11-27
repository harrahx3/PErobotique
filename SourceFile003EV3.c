#pragma config(Sensor, S1,     eyes,           sensorEV3_IRSensor)
#pragma config(Motor,  motorA,          motorEyes,     tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          motorRight,    tmotorEV3_Large, PIDControl, reversed, driveRight, encoder)
#pragma config(Motor,  motorD,          motorLeft,     tmotorEV3_Large, PIDControl, reversed, driveLeft, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task turn()
{
	while (true){
		setMotorTarget(motorEyes, -45, 20);
		waitUntilMotorStop(motorEyes);
		setMotorTarget(motorEyes, 45, 20);
		waitUntilMotorStop(motorEyes);
	}
}

task main()
{
	int i = 1;
	float target = -45;
	int robotSpeed = 40;
	int eyesSpeed = 100;


	while(true){
		startTask(turn);

		setMotorSpeed(motorLeft, robotSpeed);
		setMotorSpeed(motorRight, robotSpeed);

		while(getIRDistance(eyes) > 50) {

		}

		suspendTask(turn);

		setMotorSpeed(motorRight, 0);
		setMotorSpeed(motorLeft, 0);

		while(getIRDistance(eyes)<60) {

		}

	}
}
