---
title: "Delta MP3 Player"
github: "https://github.com/Edawg0/Delta-MP3-Player"
description: "This is my take on an original MP3 Player!"
created_at: "2026-11-01"
total_time: "6h"
---

## November 5, 2026: <Brand New Start>
~
**I Am Outlining Some of Parameters For My MP3 Player**

I debated whether or not to make my own PCB via KiCad but decided against it due to its complexity and my lack of PCB design experiance.
Instead, I will use this ESP-32 [Screen:](https://www.amazon.com/FREENOVE-Display-ESP32-S3-240x320-Non-Touch/dp/B0FSQLPQ6M)

![HERE](Images/ForJournal/Screenshot%202026-11-05%20201700.png)   

Along with this screen I will also buy this  [DAC:](https://www.amazon.com/ACEIRMC-Lossless-Digital-Converter-Raspberry/dp/B08YNJGSN4)

![HERE](Images/ForJournal/Screenshot%202026-11-05%20203926.png)

And A battery that looks something like  [This:](https://www.amazon.com/JLJLUP-Rechargeable-Integrated-Protection-Development/dp/B0FH9XHXRT)

![HERE](Images/ForJournal/Screenshot%202026-11-05%20204046.png)

All totaling to ~44$. Not bad, not bad at all.


**Now it's time for the game plan.**
I've done some research over what I am going to do,
Here's the gist:
* I need to solder the BCK, DIN and SCK pins to the ESP-32 as I don't have access to the correct GPIO pins on the current board,
* For coding, core 1 will be used for the audio decoding while core 0 will be used for wifi, bluetooth, SD card reading and whatever else needs to be done.
  - This is so the audio that is decoded stays crisp and stable.
  - and frankly because anything else can studder and I don't think anyone would care.
* I also want decrease the amount of uncalled for noise on the DAC by:
  - Using a power regulator or adding a 10 microF plus a 0.1 microF ceramic capacitor.
  - Use short, tidy wiring and keep them away from other components.

*Fun fact: I actually almost lost this whole entry due to me pressing the back button on my mouse, thank god for session storage :)*


**Logo Time!**
I was thinking that since I am calling this thing the "Delta" MP3 player I should make the logo a triangle, so I drew a little scretch:

![HERE](Images/ForJournal/Logo_Sketch.jpg)

> **Why** does it look like that?

I don't know, I thought it was cool.

Well that will do it for today. I quite enjoyed researching my parts and outlining a plan. Now that I think about it I should implement an actual goal for this project, but that will have to wait until tommorrow.
In short:
* I found the parts I needed
* I outlined some of the wiring and procedures
* I outlined some coding required

Hopefully I'll make these entrees more polished soon, but for now I'm going to bed, goodnight!

**Total time spent: 2h**

## November 10, 2026: <Intermission>

**Now I want to start creating some code first.**

The code should:
1. Read inputs from the touch screen.
2. The screen should have menus that you can navigate via touch.
3. The board should read MP3/flac files from the sd card reader.
4. The board should be able to decode the audio and send it to the DAC
(The above listed are my minimum product, some other things that would be handy are:)
5. A battery% icon with screen dimming.
6. A local host website where you can upload MP3's too.
>That's alot for someone like me, but I think I can do it!

To make the gui, I will be using LVGL for the UI because I want to create the UI within 30 hours, and make it look good ;)
To get started, I looked through the documentation on the LVGL website and install the LVGL Pro Editor and trying to set up platformio on VSCode

Anyways I gotta hop on fort, goodbye.
**Total Time Spent: 1h**

## November 11, 2026: <Starting To Code>
**Today I plan to code, code and code**

Today I spent a crap ton of time reading the LVGL documentation and reminicing at how bad my coding skills are!
(They will get better hopefully)

I drew up some menu options in my notebook,

I also add the main configurations of the ScLib.h, ScLib.cpp, AppUI.h and AppUI.cpp files.
My only problem with these is that its mainly code I got online which means I dont really **understand** the code very well.
But I am trying my best too!

Soon enough I should be writing my own code for this no problemento,
then I'll get the crushing realization that all of my code is crap and doesnt work!
but hopefully that won't be the case.

On the other hand, I think that the LVGL logic and process is really fun and intuitive.
It really makes a good bit of sense to me which is nice.

I also realize that I need to get way better at understanding pointers because currently I don't know jack diddle about them.
That's also something I will improve on in the coming days hopefully, and probably something I'll research
in my spare time (not counted to hours)

The next time I work on this, I will begin to **actually** make the UI.

**Totall Time Spent: 3h**