<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Demo Scriptlet JSP tag</title>
</head>
<body>
 <% out.print("Counter class count value: "+foo.Counter.getCount()); %>
 <br/>
 <% int localcount=0;
 out.print("Local count value: "+(++localcount)); %>
 <br/>
 <% out.print(Math.random()*50); %> 
</body>
</html>