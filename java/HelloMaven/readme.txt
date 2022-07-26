mvn archetype:generate -DarchetypeGropuId=org.apache.maven.archetypes -DarchetypeArtifactId=maven-archetype-simple -DarchetypeVersion=1.4
#com.ex.demomaven
#demo-maven-java
mv demo-maven-java HelloMaven
mvn compile
mvn install
java -cp target/demo-maven-java-1.0-SNAPSHOT.jar com.ex.demomaven.App
java --class-path=target/demo-maven-java-1.0-SNAPSHOT.jar com.ex.demomaven.App
java -classpath target/demo-maven-java-1.0-SNAPSHOT.jar com.ex.demomaven.App
mvn test
jar -tf target/demo-maven-java-1.0-SNAPSHOT.jar 
