# Illumination2PRO

A Project to turn an old ETR Luna24 Lightingdesk into a modern custom build MIDI Lighting-Controller, using Arduino, cpp and python.
I can recommend the open source software [Q Light Controller + (qlc+)](https://github.com/mcallegari/qlcplus) by [Massimo Callegari](https://github.com/mcallegari) (no ad, im just very happy with the software)

[![Arduino Build and Test](https://github.com/ClarkLiam/il2p/workflows/Arduino%20Build%20and%20Test/badge.svg)](https://github.com/ClarkLiam/il2p/actions?query=workflow:"Arduino+Build+and+Test")
[![issues - il2p](https://img.shields.io/github/issues/ClarkLiam/il2p)](https://github.com/ClarkLiam/il2p/issues)
[![GitHub release](https://img.shields.io/github/release/ClarkLiam/il2p?include_prereleases=&sort=semver&color=blue)](https://github.com/ClarkLiam/il2p/releases/)
[![License](https://img.shields.io/badge/License-MIT-blue)](https://github.com/ClarkLiam/il2p/blob/main/LICENSE)

This Repository contains the custom software for the controlling PC as well as the code and libraries for the arduino based systems.
At some point there may also be custom 3D CAD and qlc+ files available.
Currently the following hardware is in use: 2x Arduino Mega, 2x Arduino Uno

>[!CAUTION]
> A lot of the software is incomplete or buggy. Please wait for stable releases before trying to recreate this project, or be willing to search for code issues for hours.

## Current Versions:

  ### Firmeware Version:
    UNO(master):      1.8.5 pre-alpha 
    UNO(display):      1.1.2 pre-alpha
    Mega(A):           1.8.3 pre-alpha
    Mega(B):          1.8.3 pre-alpha

  ### OS-Version:
  
    1.0 pre-alpha (based on Win11 Pro)

  ### WebOS Version:
  
    1.2.2 pre-alpha

  ### Library Versions:

    DigitDisplay: 2.2.3 RTM (currently not needed)
    IlluminationDisplay: 1.0.2 RTM (currently not needed) 

> [!NOTE]
>Other libraries needed are:
>[Wire.h]()
>[Midi.h]()
>[PCF8574.h](https://github.com/xreef/PCF8574_library)

>[!TIP]
> The Software used to convert the Serial Midi Signal to a real/virtual Midi device on the host PC is called [HairlessMidi](https://projectgus.github.io/hairless-midiserial/). For more information check the developers Page

