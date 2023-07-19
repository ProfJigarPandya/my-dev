<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="foo.*" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Demo Expression JSP tag</title>
</head>
<body>
 Counter class count value: <%=Counter.getCount()  %>
 <br/>
 <% int localcount=0; %>
 Local count value: <%= ++localcount %>
 <br/>
 <%= Math.random()*50 %> 
</body>
</html>