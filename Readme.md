## Names 
Kodey Boreo and Phillip Tesolin 
   
## Design Overview
The purpose of this project is to control the speed of a DC motor
through the use of a properly tuned PID controller. Upon receiving a
desired speed the controller will ramp the current motor speed past
the set point then settle on it in a manner that will result in the distance
traveled (if connected to a vehicle) will be equal to the distance
traveled if the motor velocity response was instantaneous.
    
## Hardware List
Tiva C Series Launchpad
Motor - Pololu 30:1 Metal Gearmotor 37Dx68L MM with a 64 CPR Encoder
Power N-Channel MOSFET 30V 60A P/N - IRLB8721PbF
Voltage Divider 

## Hardware Description
The motor's natural response was improved using a root locus design and adding overshoot. Then the transient response was improved further.  All of this can be seen below.

![schematic](https://github.com/Kboreo/ESAL_Final_Project/blob/master/images/natural_response_graph.JPG)     
**Natural Response Graph**

![schematic](https://github.com/Kboreo/ESAL_Final_Project/blob/master/images/natural_response.JPG)     
**Natural Response Block Diagram**


![schematic](https://github.com/Kboreo/ESAL_Final_Project/blob/master/images/root_locus.JPG)

**Root Locus for Improved Step Response**

![schematic](https://github.com/Kboreo/ESAL_Final_Project/blob/master/images/overshoot_step_response.JPG)

**Step Response**      

![schematic](https://github.com/Kboreo/ESAL_Final_Project/blob/master/images/root_locus_for_improved_transient_response.JPG)

**Root Locus For Improved Transient Response**

![schematic](https://github.com/Kboreo/ESAL_Final_Project/blob/master/images/root_locus_for_improved_transient_response2.JPG)

**Root Locus**

![schematic](https://github.com/Kboreo/ESAL_Final_Project/blob/master/images/improved_step_response_graph.JPG)

**Graph for the Imptoved Step Response**

![schematic](https://github.com/Kboreo/ESAL_Final_Project/blob/master/images/improved_block_diagram.JPG)

**Block Diagram of Improved Transient Response**


## Software Project File Structure


<pre><code>├── project
    |   ├── .gitignore                <em>(list of files to ignore in Repo)</em>
    |   ├── README.md                 <em>(a README file in markup language)</em>
    |   ├── project.uvprojx           <em>(the keil project file)</em>
    |   ├── project.c                 <em>(main c file)</em>
    |   ├── project.h                 <em>(main header)</em>
    |   ├── project.sct               <em>(scatter file)</em>
    |   ├── startup_rvmdk.S           <em>(startup file in asm)</em>
    |   ├── src                       <em>(Directory .c and .h files)</em>
	       ├── Encoder.c            <em>(C file that handles all of the Encoder functionality)</em>
	       ├── Encoder.h            <em>(H file for Encoder functionality)</em>
	       ├── myPWM.c  	         <em>(C file for PWM functionality)</em>
	       ├── myPWM.h  	         <em>(H file for PWM functionality)</em>
	       ├── Float_Setup.c  	 <em>(C file for setting up Floating Point)</em>
	       ├── Float_Setup.h  	 <em>(H file for setting up Floating Point)</em>
	       ├── Uart_helper.c  	 <em>(C file for setting up the Uart functionality)</em>
	       ├── Uart_helper.h  	 <em>(H file for setting up the Uart functionality)</em>
	       ├── Read_Encoder.c  	 <em>(C file for reading the current speed from the encoder)</em>
	       ├── Read_Encoder.h  	 <em>(H file for reading the current speed from the encoder)</em>
	       ├── Speed_Control.c  	 <em>(C file for Controlling the speed of the motor based on user input)</em>
	       ├── Speed_Control.h  	 <em>(H file for Controlling the speed of the motor based on user input)</em>
	       ├── Get_Speed.c  	 <em>(C file for getting speed from user)</em>
	       ├── Get_Speed.h  	 <em>(H file for getting speed from user)</em>
	       ├── Calibrate.c  	 <em>(C file that handles the calibration of a motor based on a step input)</em>
	       ├── Calibrate.h  	 <em>(H file that handles the calibration of a motor based on a step input)</em>
	       ├── HAL_ADC.c  	  	 <em>(C file that sets up the hardware that is used in ADC)</em>
	       ├── HAL_ADC.h  	  	 <em>(H file that sets up the hardware that is used in ADC)</em>
	       ├── myGPIO.c  	  	 <em>(C file that handles all of the general purpose IO for the project)</em>
	       ├── myGPIO.h  	  	 <em>(H file that handles all of the general purpose IO for the project)</em>
	       └── ...  			
    |   ├── inc                       <em>(Directory for precompiled libraries and headers)</em>
    |       ├── *.h files             <em>(*.h , the menu for micro controller)</em>
    |       ├── *.lib files           <em>(*.lib ,precompiled libraries)</em>
    |       └── ...  
    |   ├── driverlib                 <em>(Directory for driver libraries source)</em>
	|       └── ...    |       
    └── </code></pre>

## Summary and Conclusions
This project was a good reminder of control systems and how important they are.  This project involved many different modules that we learned from the first half of the class.  
Here are some of the modules used in this project:
 
**GPIO**
**UART**
**PWM**
**ADC**

Overall this project had a variety of different modules and was a great learning experience.  
