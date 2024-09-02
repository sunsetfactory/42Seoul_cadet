import { Component } from "../core/seokjyan"
import movieStore, { searchMovies } from "../store/movie"

export default class Search extends Component {
	render() {
		this.el.classList.add('search')
		this.el.innerHTML = /*html*/`
			<input placeholder="Enter the movie title to search!">
			<button class="btn btn-primary">
				Search!
			</button>
		`
		const inputEl = this.el.querySelector('input')
		console.log(inputEl)
		inputEl.addEventListener('input', () => {
			movieStore.state.searchText = inputEl.value
		})
		console.log(inputEl)
		inputEl.addEventListener('keydown', event => {
			if (event.key === 'Enter' && movieStore.state.searchText.trim()) {
				searchMovies(1)
			}
		})
		console.log(inputEl)
		const btnEl = this.el.querySelector('.btn')
		btnEl.addEventListener('click', () => {
			if (movieStore.state.searchText.trim()) {
				searchMovies(1)
			}
		})
	}
}