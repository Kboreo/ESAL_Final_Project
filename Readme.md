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

![schematic](https://github.com/Kboreo/ESAL_Final_Project/blob/master/images/root_locus_for_improved_transient_response.JPG}
**Root Locus For Improved Transient Response**

![schematic](https://github.com/Kboreo/ESAL_Final_Project/blob/master/images/root_locus_for_improved_transient_response2.JPG}
**Root Locus**

![schematic](https://github.com/Kboreo/ESAL_Final_Project/blob/master/images/improved_step_response_graph.JPG}
**Graph for the Imptoved Step Response**

![schematic](https://github.com/Kboreo/ESAL_Final_Project/blob/master/images/improved_block_diagram.JPG)
**Block Diagram of Improved Transient Response**


## Software Description
C files added by users, special functions, important functions, software flow, etc.   Flowcharts are also fine.  

The file structure for this projects is as follows:

<pre><code>├── project_template
    |   ├── .gitignore                <em>(list of files to ignore in Repo)</em>
    |   ├── README.md                 <em>(a README file in markup language)</em>
    |   ├── project.uvprojx           <em>(the keil project file)</em>
    |   ├── project.c                 <em>(your main c file)</em>
    |   ├── project.h                 <em>(your main header)</em>
    |   ├── project.sct               <em>(scatter file)</em>
    |   ├── startup_rvmdk.S           <em>(startup file in asm)</em>
    |   ├── src                       <em>(Directory for your .c and .h )</em>
            ├── *.c files             <em>(*.c , the meat of the code)</em>
            ├── *.h files             <em>(*.h , the menu of the code)</em>
    |       └── ...  
    |   ├── inc                       <em>(Directory for precompiled libraries and headers)</em>
    |       ├── *.h files             <em>(*.h , the menu for micro controller)</em>
    |       ├── *.lib files           <em>(*.lib ,precompiled libraries)</em>
    |       └── ...  
    |   ├── driverlib                 <em>(Directory for driver libraries source)</em>
    |       ├── *.h files             
    |       ├── *.c files
    |       └── ...  
    └── </code></pre>

## Summary and Conclusions
Put something here that shows you learned something and / or you understand what you are talking about.  
