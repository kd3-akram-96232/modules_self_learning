

<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib uri="jakarta.tags.core" prefix="c"%>

<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Products</title>

</head>

<body>

<div class="container">

    <h2>Product List</h2>

    <table>

        <thead>
            <tr>
                <th>ID</th>
                <th>Product Name</th>
                <th>Price (₹)</th>
                <th>Stock</th>
            </tr>
        </thead>

        <tbody>

            <c:forEach var="product" items="${requestScope.product_list}">
                <tr>
                    <td>${product.product_id}</td>
                    <td>${product.product_name}</td>
                    <td class="price">${product.price}</td>
                    <td class="stock">${product.stock}</td>
                </tr>
            </c:forEach>

        </tbody>

    </table>

</div>

</body>
</html>