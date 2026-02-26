import {Component} from '@angular/core';

@Component({
  selector: 'app-root',
  template: ` Hello Universe 
  `,
  styles: `
    :host {
      color: #a144eb;
    }
  `,
})
export class App {}
//2
import {Component} from '@angular/core';

@Component({
  selector: 'app-root',
  template: ` Hello {{ city }}, {{ 1 + 1 }} `,
})
export class App {
  city = 'San Francisco';
}



