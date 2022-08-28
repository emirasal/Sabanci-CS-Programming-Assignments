# Emir Asal

movies_quotas_genres = input("Please enter movie names and remaining quota: ")
movie = input("Please enter the movie you want to watch: ")
replaced_list = movies_quotas_genres.replace(",", ":")
splitted_list = replaced_list.split(":")

if movie in splitted_list:
    tickets = int(input("Please enter the number of tickets you want to buy: "))
    total_seat = 0
    for i in range(len(splitted_list)):
        if splitted_list[i] == movie:
            seat_index = i + 1
            total_seat += int(splitted_list[seat_index])
    if tickets > total_seat:
        genre_index = seat_index + 1
        genre = splitted_list[genre_index]
        movie_list = []
        for i in range(len(splitted_list)):
            if splitted_list[i] == genre:
                mindex = i - 2
                mname = splitted_list[mindex]
                total_seat1 = 0
                for x in range(len(splitted_list)):
                    if splitted_list[x] == mname:
                        sindex = x + 1
                        seat = int(splitted_list[sindex])
                        total_seat1 += seat
                if mname not in movie_list and mname != movie and total_seat1 >= tickets:
                    movie_list.append(mname)
        if len(movie_list) != 0:
            sorted_list = sorted(movie_list)
            print("There are not enough seats for", movie + "!", "But you can watch one of the following movies from the genre", genre + ":")
            for movie in sorted_list:
                print("*", movie)
        else:
            print("There are not enough seats for", movie, "and any other movie with the genre", genre + "!")    
    else:
        print("The reservation is done!")              
else:
    print("There is no such movie in the theater.")

    
