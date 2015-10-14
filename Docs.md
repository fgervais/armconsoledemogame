# Introduction #

First off, you're gonna need SDL, Cygwin and a development tool (So far we did it with VS 2010 and Eclipse Galileo). We're just starting of so don't worry, we'll complete this documentation as we advance in our game.

Update, the docs for the windows Setup is now available as a wiki and as files on the SVN: SetupWindows

**IMPORTANT**
<br />
There are some constraints to follow for the project to be portable to the console.
  * Data types
    * No _int_, Use **uintX`_`t** (where X can be 32, 16 or 8)
      * For _signed integer_, use **intX`_`t** (where X can be 32, 16 or 8)
    * No _String_ (not even functions in the string library), Use **char`*`**
    * No _boolean_, use **uint8`_`t (0,1)**
  * Prohibited librairies
    * String
    * libstd++
      * No _ifstream/ofstream_

It is important that you follow those constraints for the code to be optimized and the binary to be light-weighted.