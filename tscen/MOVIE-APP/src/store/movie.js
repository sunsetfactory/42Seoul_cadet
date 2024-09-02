import Search from "../components/Search"
import { Store } from "../core/seokjyan"

const store = new Store({
	searchText: '',
	page: 1,
	movies: []
})

export default store
export const searchMovies = async page => {
	if (page === 1) {
		store.state.page = 1
		store.state.movies = []
	}
	const res = await fetch(`https://www.omdbapi.com/?apikey=7035c60c&s=${store.state.searchText}&page=${page}`)
	const json = await res.json()
	store.state.movies = [
		...store.state.movies,
		...json.Search
	]
}