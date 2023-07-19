Jigar-Pandyas-MacBook:HelloProperties JigarPandya$ ant clean
Buildfile: /Users/JigarPandya/Desktop/lect2/HelloProperties/build.xml

clean:
   [delete] Deleting directory /Users/JigarPandya/Desktop/lect2/HelloProperties/classes

BUILD SUCCESSFUL
Total time: 1 second
Jigar-Pandyas-MacBook:HelloProperties JigarPandya$ ant compile
Buildfile: /Users/JigarPandya/Desktop/lect2/HelloProperties/build.xml

compile:
    [mkdir] Created dir: /Users/JigarPandya/Desktop/lect2/HelloProperties/classes
     [echo] Properties Tutorial is using javac as Java compiler
    [javac] Compiling 1 source file to /Users/JigarPandya/Desktop/lect2/HelloProperties/classes

BUILD SUCCESSFUL
Total time: 4 seconds
Jigar-Pandyas-MacBook:HelloProperties JigarPandya$ ant run
Buildfile: /Users/JigarPandya/Desktop/lect2/HelloProperties/build.xml

run:
     [java] Message is : HelloWorldThisIsReadFromPropertiesFile
     [java] Version is : 3.0
     [java] Release Date is : Jan 01, 2015
     [java] DB User is : scott1
     [java] DB Password is : tiger

BUILD SUCCESSFUL
Total time: 1 second
Jigar-Pandyas-MacBook:HelloProperties JigarPandya$
