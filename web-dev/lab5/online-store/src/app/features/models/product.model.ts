export interface Product {
  id: number;
  name: string;
  categoryId: number;
  description: string;   // 2–3 sentences
  price: number;         // KZT
  rating: number;        
  image: string;         // main image URL or local path
  images: string[];      // min 3
  link: string;
  likes: number;         
}
