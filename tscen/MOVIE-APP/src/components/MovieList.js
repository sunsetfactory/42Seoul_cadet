import { Component } from "../core/seokjyan"
import movieStore from "../store/movie"

export default class MovieList extends Component {
	render() {
		this.el.classList.add('movie-list')
		this.el.innerHTML = /*html*/`
			<div class="movies"> </div>
		`
		const movieEl = this.el.querySelector('.movies')
		console.log('title', movieStore.state.movies, movieEl)
		movieEl.append(
			movieStore.state.movies.map(movie => {
				return movie.Title
			})
		)
	}
}