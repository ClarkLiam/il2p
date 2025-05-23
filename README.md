# Illumination2PRO

Project to turn an old ETR Luna24 Lightingdesk into a modern custom build MIDI Lighting-Controler to use with QLC+ (or any other MIDI Software).

Repository contains the custom software for the controlling PC as well as the code and libraries for the arduino based systems.
At some point there may also be custom 3D CAD and QLC+ files available.
Currently the following hardware is in use: 2x Arduino Mega (by Elegoo), 1x Arduino Uno

>[!CAUTION]
> A lot of the software is incomplete or buggy. Please wait for stable releases bevor trying to recreate this project, or be willing to search for code isuues for hours.

## Current Versions:

  ### Firmeware Version:
  
    UNO:   1.8.3 pre-alpha
    MegaA: 1.8.3 pre-alpha
    MegaB: 1.8.3 pre-alpha

  ### OS-Version:
  
    1.0 pre-alpha (based on Win10 Pro)

  ### WebOS Version:
  
    1.2.2 pre-alpha

  ### Library Versions:

    DigitDisplay: 2.2.3 beta
    IlluminationDisplay: 1.0.2 alpha

> [!NOTE]
> To replicate you must install the custom libraries (digitdisplay) as well as (IlluminationDisplay), which can be found in the files or in a seperate repository on my GitHub </br>
>[digitdisplay](https://github.com/ClarkLiam/digitdisplay)

>[!TIP]
> The Software used to convert the Serial Midi Signal to a real/virtual Midi device on the host PC is called [HairlessMidi](https://projectgus.github.io/hairless-midiserial/). For more information check the developers Page

