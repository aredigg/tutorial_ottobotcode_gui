# OttoBotCode Tutorial: C++&nbsp;GUI&nbsp;Programming&nbsp;for&nbsp;Beginners

## The tutorial

I wanted to learn using a GUI library when making simple programs in C++ on my Mac. I found these videos on YouTube which are simple, descriptive and easy to follow. But they were for Windows and Visual Code, so I had to adapt a bit. Here are the notes I have made, and maybe it will be helpful for others.

## How to install wxWidgets on macOS

Download it from https://wxwidgets.org/downloads/ choose "Source Code" and "Source for Linux, macOS, etc" and unpack it somewhere usful. If you use Safari it will most likely be downloaded to the "Downloads" folder for your current logged on user. So then open terminal and go there.

```
cd
cd Downloads
```
If you did not unpack it already you can use the following command (you may have to change it to the filename that was downloaded)
```
tar xf wxWidgets-3.2.5.tar.bz2
```
then build it
```
cd wxWidgets-3.2.5
mkdir build-macos
cd build-macos
../configure --disable-shared --disable-pnm --disable-pcx --disable-gif --disable-iff --disable-debug_flag --disable-sys-libs --enable-universal_binary=arm64,x86_64
make -j`sysctl -n hw.ncpu`
sudo make install
```

This makes a static release version of the library and installs the source files into `/usr/local/include` and makes it as easy as possible to follow the videos. It should not require any extra software installed except Xcode. And the compiled binaries will link it statically so it should work on other Macs as is. While the video builds both a debug and 32 bit version, I chose not to do so here. 32 bit version is not supported anymore on macOS, but if you want a debug version change `--disable-debug_flag` to `--enable-debug` on the above configure line.

## Other hints

When you want to compile your wxWidgets library sources, the `wx-config` command will give you the correct compiler and linker settings you should use. It will also let you choose between different versions that you have compiled. Run `wx-config --help` to see the options. The simplest command to compile is by running
```
c++ *.cpp -o AppName `wx-config --cxxflags --libs`
```

I have used `nano` as a placeholder text editor in the notes, but any code editor is of course fine. If your text editor uses `clangd` for code completion, LSP etc., you can create a `compile_flags.txt` in your folder of your source-file, or its parent. Run this command
```
wx-config --cxxflags | tr ' ' '\n' > compile_flags.txt
```
Other relevant options may also be included into that file, i.e. `-std=c++11`.

For bigger projects you should use Make or similar.

## Episodes

* [Episode 1](Episode%201) – Installing wxWidgets
* [Episode 2](Episode%202) – Creating a Window
* [Episode 3](Episode%203) – Adding Controls
* [Episode 4](Episode%204) – Styles
* [Episode 5](Episode%205) – Events (Static Handling)
* [Episode 6](Episode%206) – Dynamic Event Handling
* [Episode 7](Episode%207) – Event Propagation
* [Episode 8](Episode%208) – Mouse Events
* [Episode 9](Episode%209) – Keyboard Events
* [Episode 10](Episode%2010) – To-Do List Application
* [Episode 11](Episode%2011) – Adaptive Layouts
* [Episode 12](Episode%2012) – wxBoxSizer
* [Episode 13](Episode%2013) – wxGridSizer
* [Episode 14](Episode%2014) – Practical Sizer Example (To-Do List)
