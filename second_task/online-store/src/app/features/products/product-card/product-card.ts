import { Component, Input } from '@angular/core';
import { CommonModule } from '@angular/common';
import { Product } from '../../models/product.model';

@Component({
  selector: 'app-product-card',
  standalone: true,
  imports: [CommonModule],
  templateUrl: './product-card.html',
  styleUrl: './product-card.css',
})
export class ProductCardComponent {
  @Input({ required: true }) product!: Product;

  selectedImage = '';

  ngOnInit(): void {
    this.selectedImage = this.product.image;
  }

  selectImage(url: string): void {
    this.selectedImage = url;
  }

  get fullStars(): number {
    return Math.floor(this.product.rating);
  }

  get hasHalfStar(): boolean {
    return this.product.rating - Math.floor(this.product.rating) >= 0.5;
  }

  get emptyStars(): number {
    const used = this.fullStars + (this.hasHalfStar ? 1 : 0);
    return Math.max(0, 5 - used);
  }

  get kaspiUrl(): string {
    return this.product.link;
  }

  get whatsappShareUrl(): string {
    const text = `Check out this product: ${this.kaspiUrl}`;
    return `https://wa.me/?text=${encodeURIComponent(text)}`;
  }

  get telegramShareUrl(): string {
    return `https://t.me/share/url?url=${encodeURIComponent(this.kaspiUrl)}&text=${encodeURIComponent(this.product.name)}`;
  }
}
