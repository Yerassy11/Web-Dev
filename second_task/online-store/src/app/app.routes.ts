import { Routes } from '@angular/router';
import { ProductListComponent } from './features/products/product-list/product-list';


export const routes: Routes = [
  { path: '', component: ProductListComponent },
  { path: '**', redirectTo: '' },
];
