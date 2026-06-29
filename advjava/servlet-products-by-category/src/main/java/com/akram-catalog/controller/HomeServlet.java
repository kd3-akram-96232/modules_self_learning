package com.catalog.controller;
import com.catalog.entities.*;

import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletConfig;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import com.catalog.dao.CategoryDao;
import com.catalog.dao.CategoryDaoImpl;


@WebServlet(value="/homeServlet", loadOnStartup=1)
public class HomeServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private CategoryDao categoryDao;

	
	public void init(ServletConfig config) throws ServletException {
		try {
			categoryDao=new CategoryDaoImpl();
		}catch(Exception e) {
			throw new ServletException("err in init of "+getClass(),e);
		}
	}

	
	public void destroy() {
		try {
			categoryDao.cleanUp();
		}catch(Exception e) {
			System.out.println("err in destroy "+ getClass()+" "+e);
		}
	}

	
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		try {
			List<Category> categories = categoryDao.getCategoryList();
			request.setAttribute("category_list", categories);
			RequestDispatcher rd = request.getRequestDispatcher("/WEB-INF/views/home.jsp");
			rd.forward(request, response);
		}catch(Exception e) {
			throw new ServletException("err in doGet"+getClass(),e);
		}
	}

}
