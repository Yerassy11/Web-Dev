from django.urls import path
from . import views

urlpatterns = [
    # PRODUCTS
    path('products/', views.products_list),
    path('products/<int:id>/', views.product_detail),

    # CATEGORIES
    path('categories/', views.categories_list),
    path('categories/<int:id>/', views.category_detail),
    path('categories/<int:id>/products/', views.category_products),
]