import { Component, input,signal,effect, output } from '@angular/core';
import { CommonModule } from '@angular/common';
import { Product } from '../../models/product.model';

@Component({
  selector: 'app-product-item',
  standalone: true,
  imports: [CommonModule],
  templateUrl: './product-item.html',
  styleUrl: './product-item.css',
})

export class ProductItemComponent {
  product = input.required<Product>();
  delete = output<number>();

  selectedImage = signal<string>('');

  constructor() {
  effect(() => {
    this.selectedImage.set(this.product().image); // или images[0]
  });
}

  selectImage(url: string): void {
    this.selectedImage.set(url);
  }

  like(): void {
    // мгновенно обновится, т.к. объект общий для карточки
    this.product().likes += 1;
  }

  requestDelete(): void {
    const ok = confirm('Are you sure you want to delete this product?');
    if (!ok) return;
    this.delete.emit(this.product().id);
  }

  get whatsappShareUrl(): string {
    const text = `Check out this product: ${this.product().link}`;
    return `https://wa.me/?text=${encodeURIComponent(text)}`;
  }

  get telegramShareUrl(): string {
    return `https://t.me/share/url?url=${encodeURIComponent(this.product().link)}&text=${encodeURIComponent(this.product().name)}`;
  }

  onImgError(event: Event): void {
    (event.target as HTMLImageElement).src = 'products/placeholder.png';
  }
}