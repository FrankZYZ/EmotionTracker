# Emotion Recorder with Arduino MKR IoT Carrier

This code provides an example implementation of an emotion recorder using an Arduino MKR IoT Carrier board. The board has four touch buttons that correspond to different emotions, and it allows the user to record short audio clips for each emotion by pressing and holding the corresponding button. The board also has an LCD display that shows the status of each recording.

## Dependencies

This code uses the following libraries:

- Arduino_MKRIoTCarrier.h: This library provides the interface to the MKR IoT Carrier board, including the touch buttons, buzzer, and display.

## Usage

To use this code, you will need an Arduino MKR IoT Carrier board and a speaker or headphones to play back the recorded clips.

1. Connect the board to your computer via USB and upload the code using the Arduino IDE.

2. Once the code is uploaded, press and hold one of the four touch buttons to start recording a clip for the corresponding emotion. The LCD display will show a red dot to indicate that the board is recording.

3. After 1.5 seconds, the LCD display will show a green check mark to indicate that the recording is complete. You can then release the button.

4. To play back a recording, press the same button again. The LCD display will show a red dot to indicate that the board is playing the recording.

5. To stop playback, press the same button again. The LCD display will show a green check mark to indicate that playback is complete.
You can repeat steps 2-5 for each of the four touch buttons to record and play back clips for each emotion.

## Code Structure
The code is structured as follows:

- The setup() function initializes the board and sets the initial state of the LCD display.
- The loop() function reads the state of each touch button and updates the LCD display accordingly.
- The check_other_if_recording() function checks whether any other buttons are currently recording, to prevent multiple recordings from occurring simultaneously.
- The reset_time() function resets the recording start time for a given button.
- The play_beep() function plays a short beep sound to indicate the start or end of a recording.
- The show() function updates the LCD display to show the status of a given button.
- The buttonPressStartTime[], buttonPressDuration[], buttonPressCount[], plus_now[], and recording_status[] arrays keep track of the state of each touch button and its corresponding recording.

## Customization
You can customize this code by modifying the following variables:

- emotions[]: This array defines the names of the four emotions. You can change the names to fit your needs.
- colors[]: This array defines the colors used to display each emotion on the LCD display. You can change the colors to fit your preferences.
