

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib uri="jakarta.tags.core" prefix="c"%>

<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Product</title>

</head>
<body>

<div class="container">

    <h2>Product Catalog</h2>

    <form action="product" method="post">

        <label>Select Category</label>

        <select name="categoryId">
            <c:forEach var="category" items="${requestScope.category_list}">
                <option value="${category.category_id}">
                    ${category.category_name}
                </option>
            </c:forEach>
        </select>

        <input type="submit" value="Show Products">

    </form>

</div>

</body>
</html>