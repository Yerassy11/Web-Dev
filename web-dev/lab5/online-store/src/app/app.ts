import { Component, computed, inject, signal } from '@angular/core';
import { CommonModule } from '@angular/common';
import { ProductListComponent } from './features/products/product-list/product-list';
import { ProductService } from './services/product.service';

@Component({
  selector: 'app-root',
  standalone: true,
  imports: [CommonModule, ProductListComponent],
  templateUrl: './app.html',
  styleUrl: './app.css',
})
export class AppComponent {
  private readonly productService = inject(ProductService);

  readonly categories = this.productService.categories;

  readonly selectedCategoryId = signal<number | null>(null);

  readonly selectedProducts = computed(() => {
    const id = this.selectedCategoryId();
    if (id === null) return [];
    return this.productService.getProductsByCategory(id).map(p => ({ ...p }));
  });

  selectCategory(id: number): void {
    this.selectedCategoryId.set(id);
  }

  isSelected(id: number): boolean {
    return this.selectedCategoryId() === id;
  }
}