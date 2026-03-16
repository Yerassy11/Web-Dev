import { Component, effect, input, signal } from '@angular/core';
import { CommonModule } from '@angular/common';
import { Product } from '../../models/product.model';
import { ProductItemComponent } from '../product-item/product-item';

@Component({
  selector: 'app-product-list',
  standalone: true,
  imports: [CommonModule, ProductItemComponent],
  templateUrl: './product-list.html',
  styleUrl: './product-list.css',
})
export class ProductListComponent {
  products = input<Product[]>([]);

  
  readonly visibleProducts = signal<Product[]>([]);

  constructor() {
    effect(() => {
      this.visibleProducts.set(this.products());
    });
  }

  onDelete(productId: number): void {
    this.visibleProducts.set(this.visibleProducts().filter(p => p.id !== productId));
  }
}