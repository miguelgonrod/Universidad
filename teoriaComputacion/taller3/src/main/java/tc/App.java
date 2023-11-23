package tc;

import java.io.FileNotFoundException;

import io.reactivex.rxjava3.core.Observable;
import tc.json.Meteorite;

/**
 * Implemente las siguientes funciones.
 * Está permitido agregar nuevos métodos y atributos a esta clase, o crear
 * nuevas clases y usarlas aquí
 * Está prohibido:
 * - Utilizar ciclos
 * - Efectos laterales. Modificar variables o colecciones (por ejemplo, insertar
 * elementos en un arreglo)
 * - Modificar los parámetros o los tipos de dato de retorno de las funciones en
 * `App.java`
 */
public class App {

    private Datos<Meteorite> datos = new Datos<Meteorite>("json/meteorites.json", Meteorite.class);

    public static void main(String[] args) throws FileNotFoundException {
        new App().run();
    }

    public void run() {
        // Ejemplo: imprime los nombres de todos los meteoritos
        //datos.getObservable().subscribe(m -> System.out.println(m.getName()));

        // Debe imprimir por pantalla:
        // Abee
        // Adhi Kot
        // Indarch
        meteoriteNamesByClass("EH4").subscribe(System.out::println);
        // Debe imprimir por pantalla:
        // "Bukhara"
        // "Gambat"
        // "Garhi Yasin"
        // "Jajh deh Kot Lalu"
        // "Kandahar (Afghanistan)"
        // "Karkh"
        // "Kulak"
        // "Mamra Springs"
        // "Sindhri"
        meteoritesWithinRectangle(60f, 70f, 10f, 50f).subscribe(System.out::println);
    }

    /**
     * Problema 1 (50%).
     * Dado una clase de meteorito (atributo "recclass" en el archivo json),
     * retornar los nombres de todos los meteoritos que son de esa clase.
     */
    public Observable<String> meteoriteNamesByClass(String meteoriteClass) {
        return datos.getObservable().filter(m -> m.getRecclass().equals(meteoriteClass)).map(m -> m.getName());
    }

    /**
     * Problema 2 (50%).
     * Retornar el nombre de los meteoritos que estén dentro del rectánculo conformado por las coordenadas (minLong, minLat) - (maxLong, maxLat)
     * Asuma un espacio euclidiano para realizar los cálculos y que siempre se cumple que:
     * minLong < maxLong
     * minLat < maxLat
     */
    public Observable<String> meteoritesWithinRectangle(Float minLong, Float maxLong, Float minLat, Float maxLat) {
        return datos.getObservable().filter(m -> Float.parseFloat(m.getReclong()) >= minLong && Float.parseFloat(m.getReclong()) <= maxLong && Float.parseFloat(m.getReclat()) >= minLat && Float.parseFloat(m.getReclat()) <= maxLat).map(m -> m.getName());
    }
}
