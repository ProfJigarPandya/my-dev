import java.util.*;
import java.io.*;

public class HelloProperties
{
 public static void main(String [] args)
 {
  Properties properties = new Properties();

  try
  {
  FileInputStream in = new FileInputStream("data.properties");
  properties.load(in);
  in.close();
  }
  catch(Exception e)
  {
   System.out.println("");
  }	

  System.out.println("Message is : "+properties.getProperty("message"));
  System.out.println("Version is : "+properties.getProperty("version"));
  System.out.println("Release Date is : "+properties.getProperty("release_date"));

 }
}
