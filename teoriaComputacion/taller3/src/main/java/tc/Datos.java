package tc;

import java.io.FileReader;

import com.fasterxml.jackson.databind.ObjectMapper;

import io.reactivex.rxjava3.core.Observable;

public class Datos<T> {

    private String filename;
    private Class<T> clazz;

    public Datos(String filename, Class<T> clazz) {
        this.clazz = clazz;
        this.filename = filename;
    }

    public Observable<T> getObservable() {
        T[] data;
        try {
            data = (T[]) new ObjectMapper().readValue(new FileReader(filename),
                    clazz.arrayType());
            return Observable.fromArray(data);
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }

    }

}
