import {
  Component,
  Input,
  Output,
  EventEmitter,
  OnInit,
  OnChanges,
  OnDestroy,
  SimpleChanges
} from '@angular/core';

export type User = {
  id: number;
  name: string;
  email: string;
  isActive: boolean;
};

@Component({
  selector: 'app-user-card',
  templateUrl: './user-card.html',
  styleUrls: ['./user-card.css'],
})
export class UserCardComponent implements OnInit, OnChanges, OnDestroy {
 
  @Input({ required: true }) user!: User;
  @Input() showEmail = true;

  @Output() select = new EventEmitter<number>();
  @Output() toggleActive = new EventEmitter<{ id: number; isActive: boolean }>();
  @Output() delete = new EventEmitter<number>();

  ngOnInit(): void {

  }

  ngOnChanges(changes: SimpleChanges): void {

  }

  ngOnDestroy(): void {

  }

  onSelect(): void {
    this.select.emit(this.user.id);
  }

  onToggleActive(): void {
    const next = !this.user.isActive;
    this.toggleActive.emit({ id: this.user.id, isActive: next });
  }

  onDelete(): void {
    this.delete.emit(this.user.id);
  }
}
