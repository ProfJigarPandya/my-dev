javac src/com/ex/HelloJar.java -d build/
jar cfe hj.jar com.ex.HelloJar -C build/ com/ex/HelloJar.class
java -jar hj.jar
