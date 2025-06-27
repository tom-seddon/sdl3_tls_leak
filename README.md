**This repo has submodules**. Clone with `--recursive` or do `git
submodule init` then `git submodule update` after cloning.

Test program for SDL3 TLS-related leak on Windows.

Tested using Visual Studio 2019 on Windows 10 22H2 (OS Build
19045.5965).

To build, first do this from working copy:

    mkdir build
	cd build
	cmake -G "Visual Studio 16 2019" -A x64 ..
	
(If you installed CMake as part of VS2019, it'll include a suitable
cmake. Path on my PC was this: `C:\Program Files (x86)\Microsoft
Visual
Studio\2019\Professional\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe`)
	
Then load `build/sdl3_tls_leak.sln` into VS2019.

Build Debug x64.

Connect USB-type Xbox 360 controller to PC, or connect Xbox Series X
controller to PC with USB cable.

Run in debugger.

Note (hopefully!) memory leaks in output window.
